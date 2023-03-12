class Solution {
public:
    int thirdMax(vector<int>& nums) {
        set <int> numsSet;
        for(auto n : nums){
            numsSet.insert(n);
        }
        vector <int> ans;
        for(auto el : numsSet) {
            ans.push_back(el);
        }
        sort(ans.rbegin(), ans.rend());
        if(ans.size() < 3) {
            return ans[0];
        }
        return ans[2];
    }
};