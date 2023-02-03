class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroIdx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[zeroIdx++] = nums[i];
            }
        }
        for(int i = zeroIdx; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};