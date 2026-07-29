
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums)
    {
        std::sort(nums.begin(), nums.end());

        auto found = vector<vector<int>>{};

        for (size_t k = 0; k < nums.size();)
        {
            auto const target = - nums[k];

            size_t i = k+1;
            size_t j = nums.size() - 1;

            while (i < j) {
                if (nums[i] + nums[j] < target) {
                    i += 1;
                    continue;
                }
                if (nums[i] + nums[j] > target) {
                    j -= 1;
                    continue;
                }
                found.push_back({nums[k], nums[i], nums[j]});
                do { i += 1; } while (i < j && nums[i-1] == nums[i]);
                do { j -= 1; } while (i < j && nums[j+1] == nums[j]);
            }

            do { k += 1; } while (k < nums.size() && nums[k-1] == nums[k]);
        }
        return found;
    }
};
