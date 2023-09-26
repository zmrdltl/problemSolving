class Solution {
public:
    int getBitMask(int n) {
        if(!n) return 1;
        int mask = 1;
        while(mask < n) {
            mask = (mask << 1) | 1;
        }
        return mask;
    }
    int bitwiseComplement(int n) {
        return n ^ getBitMask(n);
    }
};