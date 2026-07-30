
class Solution {
public:
    uint32_t reverseBits(uint32_t n)
    {
        decltype(n) mask_i = 0x1;
        decltype(n) mask_j = 0x1 << (sizeof(n) * CHAR_BIT - 1);

        while (mask_i < mask_j)
        {
            auto const set_i = (n & mask_i);
            auto const set_j = (n & mask_j);
            n = (n & ~mask_i) | (set_j ? mask_i : 0x0);
            n = (n & ~mask_j) | (set_i ? mask_j : 0x0);

            mask_i <<= 1;
            mask_j >>= 1;
        }
        return n;
    }
};
