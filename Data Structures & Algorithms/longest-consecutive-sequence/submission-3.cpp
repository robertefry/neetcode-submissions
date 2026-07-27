
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

        auto const code = [&](auto num) -> size_t {
            size_t const bef_ftol = seq_ftol.contains(num+1) ? 1 : 0;
            size_t const aft_ltol = seq_ltof.contains(num-1) ? 1 : 0;
            return bef_ftol + aft_ltol * 2; // 0..4
        };

        for (auto num : nums) switch (code(num)) {
            break; case 0: { // not surrounding a known sequence
                seq_ftol.insert({num,num});
                seq_ltof.insert({num,num});
            }
            break; case 1: { // before a known sequence
                auto const lst = seq_ftol.at(num+1);
                seq_ftol.erase(num+1);
                seq_ftol.insert({num, lst});
                seq_ltof.at(lst) = num;
            }
            break; case 2: { // after a known sequence
                auto const fst = seq_ltof.at(num-1);
                seq_ltof.erase(num-1);
                seq_ltof.insert({num, fst});
                seq_ftol.at(fst) = num;
            }
            break; case 3: { // between two known sequences
                auto const fst = seq_ltof.at(num-1);
                auto const lst = seq_ftol.at(num+1);
                seq_ftol.erase(fst);
                seq_ftol.insert({fst,lst});
                seq_ltof.erase(lst);
                seq_ltof.insert({lst,fst});
            }
        }

        auto max_length = (int)0;

        for (auto const [first, last] : seq_ftol) {
            max_length = std::max(max_length, last - first + 1);
        }
        return max_length;
    }
};
