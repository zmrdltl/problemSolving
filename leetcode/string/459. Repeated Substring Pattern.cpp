class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string ss = s + s;
        ss = ss.substr(1, ss.size()-2);
        return ss.find(s) != string::npos;
    }
};