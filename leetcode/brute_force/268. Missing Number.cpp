class Solution {
public:
    int missingNumber(vector<int>& nums) {
        map<int,int> m;
        int ans = 0;
        for(auto n : nums) {
            m[n]++;
        }
        for(int i = 0; i <= nums.size(); i++) {
            if(m[i]) continue;
            ans = i;
            break;
        }
        return ans;
    }
};