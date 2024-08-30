class Solution {
public:
    int dfs(vector <int> nums, int idx, int currentXOR) {
        if(idx == nums.size()) {
            return currentXOR;
        }
        int include = dfs(nums, idx+1, nums[idx] ^ currentXOR);
        int exclude = dfs(nums, idx+1, currentXOR);
        return include + exclude;
    }

    int subsetXORSum(vector<int>& nums) {
        return dfs(nums, 0, 0);
    }
};
