class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0, piv = 1;
        for(int i = 0; i < 32; i++) {
            if(n & piv) {
                ans |= 1 << (31-i);
            }
            piv <<= 1;
        }
        return ans;
    }
};