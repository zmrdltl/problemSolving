class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorLimit = ceil((double)nums.size() / 2.0);
        map<int,int> frequencyMap;
        int ans = 0;
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