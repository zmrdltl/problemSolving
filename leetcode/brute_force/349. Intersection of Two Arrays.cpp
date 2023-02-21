class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        map <int, int> nums1Map;
        
        for(auto n : nums1) {
            nums1Map[n] = 1;
        }

        for(auto n : nums2) {
            if(nums1Map[n]) {
                nums1Map[n] = 0;
                ans.push_back(n);
            }
        }

        return ans;
    }
};