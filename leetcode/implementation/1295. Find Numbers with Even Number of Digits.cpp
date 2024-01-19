class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int evenNumberCount = 0;
        for(auto n : nums) {
            string sn = to_string(n);
            if(sn.size() % 2 == 0) evenNumberCount++;
        }
        return evenNumberCount;
    }
};