class Solution {
public:
    int specialArray(vector<int>& nums) {
        int ans = 0;
        for(int num = 1; num <= 1000; num++) {
            int cnt = 0;
            for(auto n : nums) {
                if(num <= n) cnt++;
            }
            if (num == cnt) {ans = num; break;}
        }
        return ans == 0 ? -1 : ans;
    }
};