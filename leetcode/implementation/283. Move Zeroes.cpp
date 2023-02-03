class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zeroCnt = 0;
        for(int i = 0; i < nums.size(); i++) {
            if(!nums[i]) zeroCnt++;
        }
        for(int i = 0; zeroCnt; i++) {
            if(!nums[i]) {
                nums.erase(nums.begin() + i);
                nums.push_back(0);
                zeroCnt--;
                i--;
            }
        }
    }
};