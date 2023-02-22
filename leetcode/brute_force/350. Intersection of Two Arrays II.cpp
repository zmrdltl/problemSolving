class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
        map <int, int> nums1Map;
        for(auto n : nums1) {
            nums1Map[n]++;
        }
        for(auto n : nums2) {
            if(nums1Map[n]) {
                nums1Map[n]--;
                ans.push_back(n);
            }
        }

        return ans;
    }
};