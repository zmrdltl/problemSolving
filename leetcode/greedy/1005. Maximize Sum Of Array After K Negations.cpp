class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        for (auto &n : nums) {
            if(k == 0) break;
            if(n > 0) continue;
            n = -n, k--;
        }
        int minNum = 0x3f3f3f3f;
        if(k % 2 == 1) {
            for(auto n : nums) {
                minNum = min(minNum, n);
            }
            for(auto &n : nums) {
                if(minNum == n) {
                    n = -n;
                    break;
                }
            }
        }
        int sum = 0;
        for(auto n : nums) {
            sum += n;
        }
        return sum;
    }
};