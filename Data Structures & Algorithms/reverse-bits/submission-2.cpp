class Solution {
public:
    uint32_t reverseBits(uint32_t value)
    {
        static_assert(CHAR_BIT * sizeof(value) == 32);

        value = ((value & 0xFFFF0000) >> 16) | ((value & 0x0000FFFF) << 16);
        value = ((value & 0xFF00FF00) >>  8) | ((value & 0x00FF00FF) <<  8);
        value = ((value & 0xF0F0F0F0) >>  4) | ((value & 0x0F0F0F0F) <<  4);
        value = ((value & 0xCCCCCCCC) >>  2) | ((value & 0x33333333) <<  2);
        value  =((value & 0xAAAAAAAA) >>  1) | ((value & 0x55555555) <<  1);
        return value;
    }
};
    