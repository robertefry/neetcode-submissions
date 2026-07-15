
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) // NOLINT
    {
        // clarify: if k+1 maximally frequent elements, which do we return?

        // 1. count the frequency of elements in nums
        auto counts = unordered_map<int,size_t>{};

        for (auto const num : nums) {
            counts[num] += 1;
        }

        // 2. bucket-sort elements with higher frequency
        auto buckets = vector<vector<int>>(nums.size()+1);

        for (auto const& [num,count] : counts) {
            buckets[count].push_back(num);
        }

        // 3. return the k most frequent elements
        auto result = vector<int>{};

        for (size_t i = buckets.size()-1; i < buckets.size(); --i) {
            for (size_t j = 0; j < buckets[i].size(); ++j) {
                if (result.size() == k) {
                    return result;
                }
                result.push_back(buckets[i][j]);
            }
        }
        return result;
    }
};
