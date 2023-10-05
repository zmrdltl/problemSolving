class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        vector <bool> ans;
        int cur = 0;
        for(auto n : nums) {
            cur = (cur * 2 + n) % 5;
            ans.push_back(!cur);
        }
        return ans;
    }
};