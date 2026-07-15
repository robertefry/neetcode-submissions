
#include <vector>
using std::vector;

#include <unordered_set>
using std::unordered_set;

class Solution {
public:
    bool hasDuplicate(vector<int>& nums)
    {
        unordered_set<int> seen {};

        for (auto const& num : nums) {
            if (seen.contains(num)) {
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};
