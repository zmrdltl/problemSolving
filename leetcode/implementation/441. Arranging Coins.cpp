class Solution {
public:
    int arrangeCoins(int n) {
        int ans = 1;
        while(1) {
            n -= ans;
            if(n <= ans) break;
            ans++;
        }
        return ans;
    }
};