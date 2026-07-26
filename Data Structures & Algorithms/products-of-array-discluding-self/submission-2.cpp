
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

        auto prod = vector<int>{};

        prod.reserve(n);
        prod.push_back(1);

        for (size_t i = 0; i < n-1; ++i) {
            prod.push_back(prod.back() * nums[i]);
        }

        auto tmp = int{1};

        for (size_t i = n-2; i < n; --i) {
            tmp *= nums[i+1];
            prod[i] *= tmp;
        }
        return prod;
    }
};
