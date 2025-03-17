class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maxWealth = 0;
        for(auto acc : accounts) {
            int wealth = 0;
            for(auto a : acc) {
                wealth += a;
            }
            maxWealth = max(maxWealth, wealth);
        }
        return maxWealth;
    }
};