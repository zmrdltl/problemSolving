class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        map <char,int> alphaIndexMap;
        int ans = -1;
        for(int i = 0; i < s.size(); i++) {
            char c = s[i];
            if(alphaIndexMap.count(c)) {
                ans = max(ans, i - alphaIndexMap[c] - 1);
            } else {
                alphaIndexMap[c] = i;
            }
        }
        return ans;
    }
};