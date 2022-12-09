class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = 0;
        int majorLimit = ceil((double)nums.size() / 2.0);
        map<int,int> frequencyMap;
        for(auto n : nums) {
            frequencyMap[n]++;
        }
        for(auto e : frequencyMap) {
            if(e.second >= majorLimit) {
                ans = e.first;
                break;
            }
        }
        return ans;
    }
};