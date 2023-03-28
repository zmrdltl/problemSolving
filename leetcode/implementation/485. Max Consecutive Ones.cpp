class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ans = 0;
        int cnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) cnt++;
            if(!nums[i] || i == nums.size() - 1) {
                ans = max(ans, cnt);
                cnt = 0;
            }
        }
        return ans;
    }
};