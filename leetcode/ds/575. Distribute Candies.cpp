class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int limit = candyType.size() / 2;
        int ans = 0;
        map <int, int> candyMapPerType;
        for(auto c : candyType) {
            candyMapPerType[c]++;
        }
        for(auto c : candyMapPerType) {
            if(ans == limit) break;
            ans++;
        }
        return ans;
    }
};