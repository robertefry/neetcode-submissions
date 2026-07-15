
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) // NOLINT
    {
        // 1. count the frequency of elements in nums
        auto counts = unordered_map<int,size_t>{};
        for (auto const num : nums) {
            counts[num] += 1;
        }

        // 2. prioritise elements with higher frequency
        using count_t = pair<int,size_t>;
        struct freq_cmp_t {
            static bool operator()(count_t const& count1, count_t const& count2) {
                return count1.second < count2.second;
            }
        };
        auto heap = priority_queue<count_t, vector<count_t>, freq_cmp_t>{};

        for (auto const& count : counts) {
            heap.push(count);
        }

        // 3. return the k most frequent elements
        auto result = vector<int>{};

        while (not heap.empty() && k > 0) {
            result.push_back(heap.top().first);
            heap.pop();
            k -= 1;
        }
        return result;
    }
};
