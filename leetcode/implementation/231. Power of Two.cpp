class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(!n) return false;
        return ceil(log2(n)) == floor(log2(n));
    }
};