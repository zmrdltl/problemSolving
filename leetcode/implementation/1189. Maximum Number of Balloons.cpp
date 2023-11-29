class Solution {
    map <char, int> alphaMap;
public:
    int maxNumberOfBalloons(string text) {
        alphaMap.clear();
        for(auto t: text) alphaMap[t]++;
        int ans = 0x3f3f3f3f;
        ans = min(alphaMap['b'], ans);
        ans = min(alphaMap['a'], ans);
        ans = min(alphaMap['l'] / 2, ans);
        ans = min(alphaMap['o'] / 2, ans);
        ans = min(alphaMap['n'], ans);
        return ans;
    }
};