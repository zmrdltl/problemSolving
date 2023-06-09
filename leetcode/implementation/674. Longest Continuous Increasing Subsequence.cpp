class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int length = 1;
        int cnt = 1;
        for(int i = 1; i < nums.size(); i++) {
            if(nums[i-1] < nums[i]) {
                cnt++;
            }
            else {
                length = max(length, cnt);
                cnt = 1;
            }
        }
        length = max(length, cnt);
        return length;
    }
};