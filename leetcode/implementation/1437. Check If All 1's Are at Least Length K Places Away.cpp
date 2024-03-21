class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        vector <int> idx;
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i]) idx.push_back(i);
        }
        if(idx.size() == 0) return true;
        for(int i = 0; i < idx.size() - 1; i++) {
            if(idx[i+1] - idx[i] - 1 < k) return false;
        }
        return true;
    }
};