class Solution {
public:
    
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;

        for(int i = 0; i < nums1.size(); i++) {
            int first = 0;
            for(int j = 0; j < nums2.size(); j++) {
                if(nums1[i] == nums2[j]) {
                    first = j;
                    break;
                }
            }
            int find = 0, second = 0;
            for(int j = first + 1; j < nums2.size(); j++) {
                if(nums2[j] > nums1[i]) {
                    second = j;
                    find = 1;
                    break;
                }
            }

            if(!find) {
                ans.push_back(-1);
            }
            else {
                ans.push_back(nums2[second]);
            }
        }
        return ans;
    }
};