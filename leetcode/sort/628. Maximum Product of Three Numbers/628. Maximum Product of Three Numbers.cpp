class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.rbegin(), nums.rend());
        int nSize = nums.size();
        return max(nums[0] * nums[1] * nums[2], nums[0] * nums[nSize-1] * nums[nSize-2]);
    }
};