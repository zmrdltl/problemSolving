class Solution {
public:
    bool canBeIncreasing(vector<int>& nums) {
        int descCnt = 0;
        int sz = nums.size();
        for(int i = 0; i < sz - 1; i++) {
            if (nums[i] >= nums[i+1]) {
                descCnt++;
                if(descCnt == 2) return false;
                if(i!=0 && nums[i-1] >= nums[i+1]) nums[i+1] = nums[i];
            }
        }

        return true;
    }
};