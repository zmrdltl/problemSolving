class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int piv = nums[0];
        int maxSum = nums[0];
        int sum = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            if (piv < nums[i]) sum += nums[i];
            else {
                maxSum = max(maxSum, sum);
                sum = nums[i];
            }
            piv = nums[i];
        }
        return max(maxSum, sum);
    }
};