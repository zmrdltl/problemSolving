struct Info {
    int index;
    int price;
};

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        vector <int> ans;
        for(int i = 0; i < prices.size(); i++) {
            Info info = {i, prices[i]};
            for(int j = i+1; j < prices.size(); j++) {
                if(info.price >= prices[j]) {
                    info.index = j;
                    info.price = prices[j];
                    break;
                }
            }
            int disCountedPrice = info.index == i ? prices[i] : prices[i] - info.price;
            ans.push_back(disCountedPrice);
        }
        return ans;
    }
};