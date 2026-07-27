
class Solution {
public:
    int longestConsecutive(vector<int>& nums)
    {
        if (nums.size() <= 1) {
            return nums.size();
        }

        // hackish bijective unordered map storing (first,last) sequence ends.
        auto seq_ftol = unordered_map<int,int>{}; // first -> last
        auto seq_ltof = unordered_map<int,int>{}; // last -> first

        for (auto num : nums)
        {
            auto fst = num;
            auto lst = num;

            if (seq_ftol.contains(num+1)) {
                lst = seq_ftol.at(num+1);
                seq_ftol.erase(num+1);
            }
            if (seq_ltof.contains(num-1)) {
                fst = seq_ltof.at(num-1);
                seq_ltof.erase(num-1);
            }

            if (seq_ftol.contains(fst)) {
                seq_ftol.at(fst) = max(seq_ftol.at(fst), lst);
            } else {
                seq_ftol.insert({fst, lst});
            }

            if (seq_ltof.contains(lst)) {
                seq_ltof.at(lst) = min(seq_ltof.at(lst), fst);
            } else {
                seq_ltof.insert({lst, fst});
            }
        }

        auto max_length = (int)0;

        for (auto const [first, last] : seq_ftol) {
            max_length = std::max(max_length, last - first + 1);
        }
        return max_length;
    }
};
