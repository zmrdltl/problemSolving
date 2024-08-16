class Solution {
public:
    int minOperations(vector<int>& nums) {
        int operation = 0;
        int pivot = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if(pivot >= nums[i]) {
                operation += pivot + 1 - nums[i];
                pivot = pivot + 1;
            } else {
                pivot = nums[i];
            }
        }
        return operation;
    }
};