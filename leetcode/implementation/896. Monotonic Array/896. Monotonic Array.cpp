class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int isIncrease = -1;
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] == nums[i+1]) continue;
            if(nums[i] < nums[i+1]) {
                if(isIncrease == 0) return false;
                isIncrease = 1;
            } else {
                if(isIncrease == 1) return false;
                isIncrease = 0;
            }
        }
        return true;
    }
};