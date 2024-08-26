class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int minDistance = 0x3f3f3f3f;
        for(int i = 0; i < nums.size(); i++) {
            if (nums[i] == target) {
                minDistance = min(minDistance, abs(i - start));
            }
        }
        return minDistance;
    }
};