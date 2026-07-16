
class Solution {
public:
    vector<int> countBits(int n)
    {
        auto result = vector<int>(n+2);
        result[1] = 1;

        for (size_t i = 1; i <= (n>>1); ++i) {
            result[2*i+0] = result[i];
            result[2*i+1] = result[i] + 1;
        }
        result.pop_back();

        return result;
    }
};
