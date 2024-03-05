class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) {
        int sz = nums.size();
        vector <int> target;
        for(int i = 0; i < sz; i++) {
            target.insert(target.begin() + index[i], nums[i]);
        }
        return target;
    }
};