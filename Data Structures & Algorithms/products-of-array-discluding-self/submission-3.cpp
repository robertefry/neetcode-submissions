
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums)
    {
        auto const n = nums.size();

        if (n == 0) {
            return {};
        }
        if (n == 1) {
            return {1};
        }

        auto prod = vector<int>(n,1);
        auto tmp = int{1};

        for (size_t i = 1; i < n; ++i) {
            prod[i] = prod[i-1] * nums[i-1];
        }
        for (size_t i = n-2; i < n; --i) {
            tmp *= nums[i+1];
            prod[i] *= tmp;
        }
        return prod;
    }
};
