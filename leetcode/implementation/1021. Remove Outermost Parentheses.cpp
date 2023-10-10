class Solution {
public:
    string removeOuterParentheses(string s) {
        int depth = 0;
        string ans;
        for(auto c : s) {
            if(c == '(' && depth++ > 0) ans += c;
            if(c == ')' && --depth > 0) ans += c;
        }
        return ans;
    }
};