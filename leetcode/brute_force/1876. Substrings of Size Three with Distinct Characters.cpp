class Solution {
public:
    bool isWordRepeated(string word) {
        map <char, int> alphaMap;
        for (char w : word) {
            if(alphaMap[w]) return true;
            alphaMap[w]++;
        }
        return false;
    }

    int countGoodSubstrings(string s) {
        int ans = 0;
        for(int i = 0; i < s.size(); i++) {
            string sub = s.substr(i,3);
            if (sub.size() < 3) continue;
            if(!isWordRepeated(sub)) ans++;
        }
        return ans;
    }
};