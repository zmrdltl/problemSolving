class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int sz = nums.size();
        return nums[sz-1] * nums[sz-2] - nums[1] * nums[0];
    }
};