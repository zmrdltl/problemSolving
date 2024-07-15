class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        int sum = 0;
        map <int, int> numCountMap;
        for(auto n : nums) {
            numCountMap[n]++;
        }
        for(auto n : numCountMap) {
            if (n.second == 1) sum += n.first;
        }
        return sum;
    }
};