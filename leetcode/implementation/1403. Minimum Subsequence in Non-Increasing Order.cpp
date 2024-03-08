class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        int sum = 0;
        vector <int> ans;
        for(auto n : nums) {
            if(totalSum - sum < sum) {
                break;
            }
            ans.push_back(n);
            sum += n;
        }
        return ans;
    }
};