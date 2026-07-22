
class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target)
    {
        // n(i,target) = n(i+1,target-nums[i]) ++ n(i+1,target)

        auto const sum = [&](auto const fn_self, auto i, auto target) -> vector<vector<int>>
        {
            if (target == 0) {
                return {{}};
            }
            if (i >= nums.size()) {
                return {};
            }

            auto result = vector<vector<int>>{};

            if (target >= nums[i])
                for (auto&& seq : fn_self(fn_self, i, target-nums[i]))
            {
                seq.push_back(nums[i]);
                result.push_back(std::move(seq));
            }

            for (auto&& seq : fn_self(fn_self, i+1, target)) {
                result.push_back(std::move(seq));
            }

            return result;
        };

        return sum(sum, 0, target);
    }
};
