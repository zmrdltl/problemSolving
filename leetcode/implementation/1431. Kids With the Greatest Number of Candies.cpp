class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int maxRepresentCandyNum = 0;
        vector <bool> canTakeMaxCandies;
        
        for(auto c : candies) {
            maxRepresentCandyNum = max(maxRepresentCandyNum, c);
        }
        
        for(auto c : candies) {
            if(c + extraCandies >= maxRepresentCandyNum) {
                canTakeMaxCandies.push_back(true);
            } else {
                canTakeMaxCandies.push_back(false);
            }
        }
        return canTakeMaxCandies;
    }
};