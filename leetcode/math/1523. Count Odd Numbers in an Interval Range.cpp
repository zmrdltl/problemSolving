class Solution {
public:
    int countOdds(int low, int high) {
        int ans = 0;
        if (low % 2) {
            ans = (high - low) / 2 + 1; 
        } else {
            ans = (high - low) / 2;
            if(high % 2) ans++;
        }
        return ans;
    }
};