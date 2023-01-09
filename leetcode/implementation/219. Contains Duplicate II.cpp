class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        map <int, int> m;
        for(int i = 0; i < nums.size(); i++) {
            if(m.count(nums[i])) {
                int j = m[nums[i]];
                if(abs(i - j) <= k) return true;
            }
            m[nums[i]] = i;
        }
        return false;
    }
};