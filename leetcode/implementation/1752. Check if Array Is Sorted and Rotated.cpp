class Solution {
public:
    bool check(vector<int>& nums) {
        int cnt = 0;
        int sz = nums.size();
        for(int i = 0; i < nums.size() - 1; i++) {
            if(nums[i] > nums[i+1]) {
                cnt++;
            } 
        }
        if(nums[sz-1] > nums[0]) cnt++;
        return cnt <= 1;
    }
};