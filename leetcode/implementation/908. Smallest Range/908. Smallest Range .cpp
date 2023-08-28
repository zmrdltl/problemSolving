class Solution {
public:
    int smallestRangeI(vector<int>& nums, int k) {
        int minNum = 0x3f3f3f3f, maxNum = 0;
        for(auto n : nums){
            minNum = min(minNum, n);
            maxNum = max(maxNum, n);
        }
        if(maxNum - k <= minNum + k) return 0;
        return maxNum - k - (minNum + k);
    }
};