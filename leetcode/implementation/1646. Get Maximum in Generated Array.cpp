class Solution {
public:
    int getMaximumGenerated(int n) {
        int ans = 0;
        vector <int> nums = {0, 1};
        if (n < 2) return nums[n];
        for(int i = 2; i <= n; i++) {
            int nextNum = nums[i/2];
            if (i % 2) {
                nextNum = nums[i/2] + nums[i/2+1];
            }
            ans = max(ans, nextNum);
            nums.push_back(nextNum);
        }
        return ans;
    }
};