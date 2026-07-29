
class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        if (nums.empty()) {
            return -1;
        }

        size_t i = 0;
        size_t j = nums.size() - 1;

        while (i < j) {
            size_t k = i + (j-i) / 2;

            if (nums[k] > nums[j]) {
                i = k + 1;  // k is strictly before the pivot
            } else {
                j = k;      // k is after (or equal to) the pivot
            }
        }

        size_t pivot = i;
        i = 0;
        j = nums.size() - 1;

        if (nums[pivot] <= target && target <= nums[j]) {
            i = pivot;
        } else {
            if (pivot == 0) {
                // nums is un-rotated and target is not in nums
                return -1;
            }
            j = pivot - 1;
        }

        while (i < j) {
            size_t k = i + (j-i) / 2;

            if (target > nums[k]) {
                i = k + 1;
            } else {
                j = k;
            }
        }

        return (nums[i] != target) ? -1 : i;
    }
};
