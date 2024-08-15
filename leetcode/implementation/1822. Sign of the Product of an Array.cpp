class Solution {
public:
    int arraySign(vector<int>& nums) {
        int productOfNums = 1;
        for (int i = 0; i < nums.size(); i++) {
            int num = nums[i];
            if (num == 0) productOfNums = 0;
            else if (num < 0) productOfNums = -productOfNums;
        }
        return productOfNums;
    }
};