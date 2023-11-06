class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map <pair<int,int>, int> countMap;
        int ans = 0;
        for(auto d : dominoes) {
            int a = min(d[0], d[1]);
            int b = max(d[0], d[1]);
            if (countMap.find({a,b}) != countMap.end()) {
                ans+= countMap[{a,b}];
            }
            countMap[{a,b}]++;
        }
        return ans;
    }
};