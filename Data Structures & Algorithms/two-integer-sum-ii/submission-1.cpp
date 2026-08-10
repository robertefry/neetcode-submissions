
#include <utility>

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target)
    {
        // assumption: not numbers.empty()

        size_t i = 0;
        size_t j = numbers.size() - 1;

        while (i < j)
        {
            if (numbers[i] + numbers[j] > target) {
                j -= 1;
                continue;
            }
            if (numbers[i] + numbers[j] < target) {
                i += 1;
                continue;
            }
            return vector<int>{ static_cast<int>(i) + 1, static_cast<int>(j) + 1 };
        }

        // assumption: there will always be one valid solution
        unreachable();
    }
};
