
class Solution {
public:
    int hammingWeight(uint32_t n)
    {
        int count = 0;

        for (uint32_t mask = 0x1; mask > 0; mask *= 2) {
            count += ((n & mask) == 0) ? 0 : 1;
        }
        return count;
    }
};
