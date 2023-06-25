class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        vector <int> sums(nums.size(), 0);
        sums[0] = nums[0];
        int pivotIdx = -1;
        for(int i = 1; i < nums.size(); i++) {
            sums[i] = sums[i-1] + nums[i];
        }
        for(int i = 0; i < sums.size(); i++) {
            int leftSum = sums[i] - nums[i];
            int rightSum = sums[nums.size() - 1] - sums[i];
            if(leftSum == rightSum) {
                pivotIdx = i;
                break;
            }
        }
        return pivotIdx;
    }
};