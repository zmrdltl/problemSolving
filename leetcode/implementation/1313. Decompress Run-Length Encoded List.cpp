class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
        vector <int> ans;
        for(int i = 0; i < nums.size() - 1; i+=2) {
            int freq = nums[i];
            int val = nums[i+1];
            for(int j = 0; j < freq; j++) ans.push_back(val);
        }
        return ans;
    }
};