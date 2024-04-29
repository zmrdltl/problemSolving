class Solution {
public:
    string modifyString(string s) {
        for(int i = 0; i < s.size(); i++) {
            if(s[i] != '?') continue;
            for(char alpha = 'a'; alpha <= 'z'; alpha++) {
                if(i > 0 && alpha == s[i-1] || (i+1) < s.size() && alpha == s[i+1]) continue;
                s[i] = alpha;
            }
        }
        return s;
    }
};