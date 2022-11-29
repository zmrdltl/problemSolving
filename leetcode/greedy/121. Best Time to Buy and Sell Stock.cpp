class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = prices[0];
        int ans = 0;
        for(int i = 0; i < prices.size(); i++){
            buy = min(buy, prices[i]);
            int curProfit = prices[i] - buy;
            ans = max(ans, curProfit);
        }
        return ans;
    }
};