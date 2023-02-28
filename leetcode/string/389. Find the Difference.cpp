class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans;
        map <char, int> sMap;
        for(auto c : s) sMap[c]++;
        for(auto c : t) {
            if(!sMap[c]) { 
                ans = c;
                break;
            }
            sMap[c]--;
        }
        return ans;
    }
};