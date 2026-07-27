
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() <= 1) {
            return nums.size();
        }

        auto const unique = set<int>{nums.begin(), nums.end()};
        auto sequences = unordered_map<int,int>{}; // last -> length

        for (auto num : unique) {
            sequences[num] = max(sequences[num], sequences[num-1] + 1);
            sequences.erase(num-1);
        }

        return std::ranges::max_element(sequences, [](auto const& seq_1, auto const& seq_2) {
            return seq_1.second < seq_2.second;
        })->second;
    }
};
