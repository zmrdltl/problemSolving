class Solution {
public:
    int balancedStringSplit(string s) {
        int ans = 0, lcnt = 0, rcnt = 0;
        for(auto c : s) {
            if(c == 'R') {
                rcnt++;
            } else {
                lcnt++;
            }
            if(rcnt == lcnt) {
                rcnt = 0;
                lcnt = 0;
                ans++;
            }
        }
        return ans;
    }
};