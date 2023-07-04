class Solution {
public:
    int dominantIndex(vector<int>& nums) {
        int maxNum = 0;
        int maxIdx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(maxNum < nums[i]) maxNum = nums[i], maxIdx = i;
        }
        for(int i = 0; i < nums.size(); i++) {
            if(i == maxIdx) continue;
            if(nums[i] * 2 > maxNum) return -1;
        }
        return maxIdx;
    }
};