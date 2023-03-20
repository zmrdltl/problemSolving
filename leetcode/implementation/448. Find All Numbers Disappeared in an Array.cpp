class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector <int> countNum(100001,0);
        vector <int> ans;
        for(auto n : nums) {
            countNum[n]++;
        }

        for(int i = 1; i <= nums.size(); i++) {
            if(!countNum[i]) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};