class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorLimit = ceil((double)nums.size() / 2.0);
        map<int,int> m;
        int ans = 0;
        for(auto n : nums) {
            m[n]++;
        }
        for(auto e : m) {
            if(e.second >= majorLimit) {
                ans = e.first;
                break;
            }
        }
        return ans;
    }
};