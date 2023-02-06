class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector <int> ans;
        int sz = nums.size();
        for(int i = 0; i < sz / 2; i++) {
            ans.push_back(nums[i]);
            ans.push_back(nums[i + sz / 2]);
        }
        return ans;
    }
};