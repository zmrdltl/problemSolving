class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> m;
        vector <int> ans;
        for(int i = 0; i < nums.size(); i++) {
            int other = target - nums[i];
            if(m.count(other)) {
                ans = {i, m[other]};
                break;
            }
            m[nums[i]] = i;
        }
        return ans;
    }
};