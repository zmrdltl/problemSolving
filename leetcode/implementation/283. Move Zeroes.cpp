class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCnt = 0;
        int nonZeroIdx = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] != 0) {
                nums[nonZeroIdx++] = nums[i];
            }
        }
        for(int i = nonZeroIdx; i < nums.size(); i++) {
            nums[i] = 0;
        }
    }
};