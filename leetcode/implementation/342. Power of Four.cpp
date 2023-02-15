class Solution {
public:
    bool isPowerOfFour(int n) {
        for(int i = 0; (1LL << i) <= n; i += 2) {
            if((1 << i) == n) return true;
        }
        return false;
    }
};