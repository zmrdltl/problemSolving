class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        map<int,int> numsMap;
        for(auto n : nums) {
            numsMap[n]++;
        }
        vector<int> ans;
        for(int i = 1; i <= nums.size(); i++){
            if(numsMap[i] > 1) ans.push_back(i);
        }
        
        for(int i = 1; i <= nums.size(); i++){
            if(!numsMap[i]) ans.push_back(i);
        }

        return ans;
    }
};