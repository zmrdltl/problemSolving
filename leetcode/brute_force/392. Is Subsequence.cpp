class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sPiv = 0;
        for(auto tt: t) {
            if(sPiv == s.size()) break;
            if(s[sPiv] == tt) sPiv++;
        }
        return sPiv == s.size();
    }
};