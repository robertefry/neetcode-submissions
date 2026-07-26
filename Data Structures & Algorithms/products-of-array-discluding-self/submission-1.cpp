
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

        auto prod_l = vector<int>(n,1);
        auto prod_r = vector<int>(n,1);

        for (size_t i = 1; i < n; ++i) {
            prod_l[i] = prod_l[i-1] * nums[i-1];
        }
        for (size_t i = n-2; i < n; --i) {
            prod_r[i] = prod_r[i+1] * nums[i+1];
        }

        auto prod = vector<int>(n);

        for (size_t i = 0; i < n; ++i) {
            prod[i] = prod_l[i] * prod_r[i];
        }
        return prod;
    }
};
