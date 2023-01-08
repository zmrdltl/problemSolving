class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map <int,int> m;
        for(auto n : nums) {
            if(m[n]) return true;
            m[n]++;
        }
        return false;
    }
};